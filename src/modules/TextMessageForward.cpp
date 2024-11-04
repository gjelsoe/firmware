#include "TextMessageForward.h"
#include "MeshService.h"
#include "NodeDB.h"
#include "PowerFSM.h"
#include "configuration.h"

TextMessageForwardModule *textMessageforwardModule;
bool RelayMessage = false;
bool MessageReply = false;
bool includesenderid = false;
char sendTo[16];


ProcessMessage TextMessageForwardModule::handleReceived(const meshtastic_MeshPacket &mp)
{
    /*
        Uncomment the preferences below if you want to use the module
        without having to configure it from the PythonAPI or WebUI.
    */
    // moduleConfig.textmessage_forward.enabled = true; // Endable Text Message Forward module.
    // moduleConfig.textmessage_forward.messagereply = true; // Reply to sender, that message has been forwarded.
    // moduleConfig.textmessage_forward.includesenderid = true; // Reply to sender, that message has been forwarded.
    // strcpy(moduleConfig.textmessage_forward.sendTo, "33637590") // Send messages to NodeID.

    strcpy(sendTo, "33637590");

    auto &p = mp.decoded;
#ifdef DEBUG_PORT
    LOG_INFO("Forwarding msg from=!%0x, id=0x%x, to=!%0x", mp.from, mp.id, mp.to);
#endif

    // We only store/display messages destined for us.
    // Keep a copy of the most recent text message.
    devicestate.rx_text_message = mp;
    devicestate.has_rx_text_message = true;

    powerFSM.trigger(EVENT_RECEIVED_MSG);
    notifyObservers(&mp);
    
//    if ((moduleConfig.textmessage_forward.enabled) && (nodeDB->getNodeNum() == mp.to)) {
    if ((RelayMessage) && (nodeDB->getNodeNum() == mp.to)) {    // Is the module enabled, are the message for us.
//        if (moduleConfig.textmessage_forward.includesenderid) {
        if (includesenderid) {  // Do we send a message with the nodeID of sender?
            char *senderStr = new char[40];
            sprintf(senderStr, "DM from !%0x :", mp.from);
            meshtastic_MeshPacket *sendID = allocDataPacket();
            sendID->to = (uint32_t)strtoul(sendTo, NULL, sizeof(sendTo));
            sendID->decoded.payload.size = strlen(senderStr);;
            memcpy(sendID->decoded.payload.bytes, senderStr, sendID->decoded.payload.size);
            service->sendToMesh(sendID);
        }
        // prepare message and re-send to owner.
        meshtastic_MeshPacket *send = allocDataPacket();
        send->to = (uint32_t)strtoul(sendTo, NULL, sizeof(sendTo));
        send->decoded.payload.size = p.payload.size;
        memcpy(send->decoded.payload.bytes, p.payload.bytes, send->decoded.payload.size);
        service->sendToMesh(send);
//        if (moduleConfig.textmessage_forward.messagereply) {
        if (MessageReply) { // Do we send a message to sender, that we have forwarded the message?
            const char *replyStr = "DM forwarded";
            auto reply = allocDataPacket();                 // Allocate a packet for sending
            reply->decoded.payload.size = strlen(replyStr); // You must specify how many bytes are in the reply
            reply->to = mp.from;
            memcpy(reply->decoded.payload.bytes, replyStr, reply->decoded.payload.size);
            service->sendToMesh(reply);
        }
    }
    return ProcessMessage::CONTINUE; // Let others look at this message also if they want
}

bool TextMessageForwardModule::wantPacket(const meshtastic_MeshPacket *p)
{
    return MeshService::isTextPayload(p);
}