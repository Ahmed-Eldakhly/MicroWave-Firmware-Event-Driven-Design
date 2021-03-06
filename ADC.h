/*******************************************************************************
 * 
 * File:                ADC.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions prototypes, enums and definitions 
 *                      of ADC peripheral.
 * 
 * Revision history:    26/2/2020
 * 
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC_H
#define	ADC_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/************************** EnumADC_channels_t ********************************/
typedef enum{
    ADC_CHANNEL_0,
    ADC_CHANNEL_1,
    ADC_CHANNEL_2,
    ADC_CHANNEL_3,
    ADC_CHANNEL_4,
    ADC_CHANNEL_5,
    ADC_CHANNEL_6,
    ADC_CHANNEL_7,
    ADC_CHANNEL_8,
    ADC_CHANNEL_9,
    ADC_CHANNEL_10,
    ADC_CHANNEL_11,
    ADC_CHANNEL_12
}EnumADC_channels_t;

/************************* EnumADC_acquisition_Time_t *************************/
typedef enum{
    ADC_ACQUISITION_TIME_0,
    ADC_ACQUISITION_TIME_2,
    ADC_ACQUISITION_TIME_4,
    ADC_ACQUISITION_TIME_6,
    ADC_ACQUISITION_TIME_8,
    ADC_ACQUISITION_TIME_12,
    ADC_ACQUISITION_TIME_16,
    ADC_ACQUISITION_TIME_20
}EnumADC_acquisition_Time_t;

/**************************** EnumADC_prescaler_t *****************************/
typedef enum{
    ADC_PRESCALER_2,
    ADC_PRESCALER_8,
    ADC_PRESCALER_32,
    ADC_OSCILLATOR_CLOCK,
    ADC_PRESCALER_4,
    ADC_PRESCALER_16,
    ADC_PRESCALER_64
}EnumADC_prescaler_t;

/************************** EnumADC_result_format_t ***************************/
typedef enum{
    ADC_RESULT_LEFT_JUSTIFIED,
    ADC_RESULT_RIGHT_JUSTIFIED
}EnumADC_result_format_t;

/**************************** EnumADC_Vref_type_t *****************************/
typedef enum{
    ADC_V_REF_HIGH,
    ADC_V_REF_LOW
}EnumADC_Vref_type_t;

/**************************** EnumADC_Vref_value_t ****************************/
typedef enum{
    ADC_V_REF_INPUT_PIN,
    ADC_V_REF_DEFAULT_VALUE
}EnumADC_Vref_value_t;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	ADC_Initialization
 *
 * Description: 	initialize ADC module with specific channel that is selected
 *                  by the user.
 *
 * Inputs:			a_ADC_channel_t (typedef for all ADC channels : EnumADC_channels_t)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void ADC_Initialization(EnumADC_channels_t a_ADC_channel_t);

/*******************************************************************************
 * Function Name:	ADC_Select_acquisition_time
 *
 * Description: 	this function allow the user to select the acquisition time to 
 *                  invoke automatically or set by user calculated delay function.
 *
 * Inputs:			a_ADC_acquisition_Time_t (typedef for all avaliable ADC
 *                  acquisition values : EnumADC_channels_t)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void ADC_Select_acquisition_time(EnumADC_acquisition_Time_t a_ADC_acquisition_Time_t);

/*******************************************************************************
 * Function Name:	ADC_Select_prescaler
 *
 * Description: 	this function allow the user to select the clock frequency for  
 *                  ADC module by devision system clock on selected pre_scaler value.
 *
 * Inputs:			EnumADC_prescaler_t (typedef for all avaliable ADC
 *                  pre_scaler values : EnumADC_prescaler_t)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void ADC_Select_prescaler(EnumADC_prescaler_t a_ADC_prescaler_t);

/*******************************************************************************
 * Function Name:	ADC_Read_value
 *
 * Description: 	this function return the value of signal that is converted by ADC.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			uint16 (result value will be in 10 bits)
 *******************************************************************************/
extern uint16 ADC_Read_value(void);

/*******************************************************************************
 * Function Name:	ADC_Start_conversion
 *
 * Description: 	start the ADC sampling process on initialized channel.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void ADC_Start_conversion(void);

/*******************************************************************************
 * Function Name:	ADC_Disable
 *
 * Description: 	Disable ADC module.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void ADC_Disable(void);

/*******************************************************************************
 * Function Name:	ADC_Set_result_format
 *
 * Description: 	select the result justification format left justification or
 *                  right justification.
 *
 * Inputs:			EnumADC_result_format_t (typedef for avaliable justification 
 *                  for result of ADC conversion).
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void ADC_Set_result_format(EnumADC_result_format_t a_ADC_result_format_t);

/*******************************************************************************
 * Function Name:	ADC_Set_Vref
 *
 * Description: 	allow the user to select the reference voltage for ADC conversion
 *                  process (max. and min. voltage) from input source on two channels 
 *                  of ADC module.
 *
 * Inputs:			EnumADC_Vref_type_t (typedef to which voltage is set(max. or min.)).
 * 
 *                  EnumADC_Vref_value_t (typedef to select the source of voltage will be
 *                  the default value on micro_controller or input on specific ADC channel).
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void ADC_Set_Vref(EnumADC_Vref_type_t a_ADC_Vref_type_t , EnumADC_Vref_value_t a_ADC_Vref_value_t);


#endif	/* ADC_H */

