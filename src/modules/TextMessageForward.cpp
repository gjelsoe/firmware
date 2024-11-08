#include "TextMessageForward.h"
#include "MeshService.h"
#include "NodeDB.h"
#include "PowerFSM.h"
#include "configuration.h"

TextMessageForwardModule *textMessageforwardModule;
bool RelayMessage = true;
bool MessageReply = true;
bool includesenderid = true;

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

    // Define the destination number as a constant to minimize stack usage
    char sendTo[16] = "33637590";
//    const uint32_t sendToAddress = strtoul(moduleConfig.textmessage_forward.sendTo, NULL, 16); // Convert once to avoid redundant calls
    const uint32_t sendToAddress = strtoul(sendTo, NULL, 16); // Convert once to avoid redundant calls
    auto &p = mp.decoded;

    // Log message forwarding
    LOG_INFO("Forwarding msg from=!%0x, id=0x%x, to=!%0x", mp.from, mp.id, mp.to);

    // Update device state and notify observers
    devicestate.rx_text_message = mp;
    devicestate.has_rx_text_message = true;
    powerFSM.trigger(EVENT_RECEIVED_MSG);
    notifyObservers(&mp);

    // Relay message only if the module is enabled and the message is intended for us
//    if ((moduleConfig.textmessage_forward.enabled) && (nodeDB->getNodeNum() == mp.to)) {
    if (RelayMessage && nodeDB->getNodeNum() == mp.to) {
        // Optional: Send a message with the sender's ID
        if (includesenderid) {
            char senderStr[30];
            snprintf(senderStr, sizeof(senderStr), "DM from !%0x :", mp.from);

            meshtastic_MeshPacket *sendID = allocDataPacket();
            sendID->to = sendToAddress;
            sendID->decoded.payload.size = strlen(senderStr);

            // Ensure payload does not exceed buffer size
            if (sendID->decoded.payload.size <= sizeof(sendID->decoded.payload.bytes)) {
                memcpy(sendID->decoded.payload.bytes, senderStr, sendID->decoded.payload.size);
                service->sendToMesh(sendID);
            }
        }

        // Prepare and send the main message to the owner
        meshtastic_MeshPacket *send = allocDataPacket();
        send->to = sendToAddress;
        send->decoded.payload.size = p.payload.size;
        memcpy(send->decoded.payload.bytes, p.payload.bytes, send->decoded.payload.size);
        service->sendToMesh(send);

        // Optional: Send confirmation to the sender if enabled
//        if (moduleConfig.textmessage_forward.messagereply) {
        if (MessageReply) {
            const char replyStr[] = "DM forwarded";
            meshtastic_MeshPacket *reply = allocDataPacket();
            reply->to = mp.from;
            reply->decoded.payload.size = strlen(replyStr);

            if (reply->decoded.payload.size <= sizeof(reply->decoded.payload.bytes)) {
                memcpy(reply->decoded.payload.bytes, replyStr, reply->decoded.payload.size);
                service->sendToMesh(reply);
            }
        }
    }

    return ProcessMessage::CONTINUE;
}

bool TextMessageForwardModule::wantPacket(const meshtastic_MeshPacket *p)
{
    return MeshService::isTextPayload(p);
}
