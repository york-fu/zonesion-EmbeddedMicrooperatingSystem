#include "sys_ui.h"


void sysUI_update()
{
    char pbuf[20] = {0};
    
    GUI_SetFont(&GUI_Font32B_ASCII);//�����С
    GUI_SetColor(GUI_WHITE);//������ɫ
    sprintf(pbuf,"GUI Example: \r\n BitmapDisplay Test");
	GUI_DispStringAt(pbuf,8,4);
    
    GUI_DrawBitmap(&bmZonesion,10,100);
    GUI_DrawBitmap(&bmZonImage,150,100);
}


void GUI_Config()
{
    GUI_SetFont(&GUI_Font8x16);//�����С
    GUI_SetBkColor(GUI_BLACK);//������ɫ     
    GUI_SetColor(GUI_WHITE);//������ɫ
}


PROCESS(SysUI_process, "system ui process");

PROCESS_THREAD(SysUI_process, ev, data)
{
    static struct etimer etimer_uiUpdate;
    
    PROCESS_BEGIN();
    
	GUI_Init();
    GUI_Config();
    process_post(&SysUI_process,PROCESS_EVENT_TIMER,NULL);
    
    while(1)
    {
        PROCESS_WAIT_EVENT();  
        if(ev == PROCESS_EVENT_TIMER)
        {
            etimer_set(&etimer_uiUpdate,100);
            sysUI_update();
        }
    }
    
    PROCESS_END();
}