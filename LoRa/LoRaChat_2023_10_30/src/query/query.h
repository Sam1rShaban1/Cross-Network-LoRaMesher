#pragma once

#include <Arduino.h>

#include <ArduinoLog.h>

#include "sensor.h"

#include "message/messageService.h"

#include "message/messageManager.h"

#include "queryCommandService.h"

#include "queryMessage.h"

#include "config.h"

#include "LoraMesher.h"

class Query : public MessageService {
public:
    /**
     * @brief Construct a new GPSService object
     *
     */
    static Query& getInstance() {
        static Query instance;
        return instance;
    }

    QueryCommandService* queryCommandService = new QueryCommandService();

    void init();

    String queryOn();

    String queryOn(uint16_t dst);

    String queryOff();

    String queryOff(uint16_t dst);

    void createAndSendQuery();

    String getJSON(DataMessage* message);

    DataMessage* getDataMessage(JsonObject data);

    DataMessage* getQueryMessage(QueryCommand command, uint16_t dst);

    void processReceivedMessage(messagePort port, DataMessage* message);

private:
    Query() : MessageService(QueryApp, "Query") {
        commandService = queryCommandService;
    };

    uint8_t queryId = 0;

    QueryCommand queryCommandS;
    u_int32_t queryvalueS;

};

    
