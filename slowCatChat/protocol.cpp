#include "protocol.h"

PDU *mkPDU(uint uiMsgLen){
    uint uiPDULen = sizeof (PDU) + uiMsgLen;

    PDU* pdu = static_cast<PDU*>(malloc(uiPDULen));//强制性转化
    if(nullptr == pdu)
    {
        exit(EXIT_FAILURE); // 错误退出程序
    }
    memset (pdu, 0, uiPDULen);
    pdu -> uiPDULen = uiPDULen;
    pdu -> uiMsgLen = uiMsgLen;

    return pdu;
}
