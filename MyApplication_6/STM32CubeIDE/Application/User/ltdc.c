#include "ltdc.h"

LTDC_HandleTypeDef hltdc;
LCD_DrvTypeDef *LcdDrv;

void MX_LTDC_Init(void) {

	/* USER CODE BEGIN LTDC_Init 0 */

	/* USER CODE END LTDC_Init 0 */

	LTDC_LayerCfgTypeDef pLayerCfg = { 0 };

	/* USER CODE BEGIN LTDC_Init 1 */

	/* USER CODE END LTDC_Init 1 */
	hltdc.Instance = LTDC;
	hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
	hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
	hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
	hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
	hltdc.Init.HorizontalSync = 9;
	hltdc.Init.VerticalSync = 1;
	hltdc.Init.AccumulatedHBP = 29;
	hltdc.Init.AccumulatedVBP = 3;
	hltdc.Init.AccumulatedActiveW = 269;
	hltdc.Init.AccumulatedActiveH = 323;
	hltdc.Init.TotalWidth = 279;
	hltdc.Init.TotalHeigh = 327;
	hltdc.Init.Backcolor.Blue = 0;
	hltdc.Init.Backcolor.Green = 0;
	hltdc.Init.Backcolor.Red = 0;
	if (HAL_LTDC_Init(&hltdc) != HAL_OK) {
		Error_Handler();
	}
	pLayerCfg.WindowX0 = 0;
	pLayerCfg.WindowX1 = 240;
	pLayerCfg.WindowY0 = 0;
	pLayerCfg.WindowY1 = 320;
	pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
	pLayerCfg.Alpha = 255;
	pLayerCfg.Alpha0 = 0;
	pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
	pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
	pLayerCfg.FBStartAdress = 0;
	pLayerCfg.ImageWidth = 240;
	pLayerCfg.ImageHeight = 320;
	pLayerCfg.Backcolor.Blue = 0;
	pLayerCfg.Backcolor.Green = 0;
	pLayerCfg.Backcolor.Red = 0;
	if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN LTDC_Init 2 */
	/*Select the device */
	LcdDrv = &ili9341_drv;
	/* LCD Init */
	LcdDrv->Init();

	LcdDrv->DisplayOff();
	/* USER CODE END LTDC_Init 2 */

}
