/*
 * SEV_SEG_int.h
 *
 *  Created on: Sep 1, 2024
 *      Author: abdullahalazhary
 */

#ifndef INCLUDE_HAL_SEVEN_SEGMENT_SEV_SEG_INT_H_
#define INCLUDE_HAL_SEVEN_SEGMENT_SEV_SEG_INT_H_

ES_T SEV_SEG_enumInit(SEV_SEG_T* Copy_pstrSegments);

ES_T SEV_SEG_enumNUMDisplay(u8 Copy_u8SegmentID,u8 Copy_u8Number);

ES_T SEV_SEG_enumCMNEnable(u8 Copy_u8SegmentID);

ES_T SEV_SEG_enumCMNDisable(u8 Copy_u8SegmentID);

ES_T SEV_SEG_enumDOTEnable(u8 Copy_u8SegmentID);

ES_T SEV_SEG_enumDOTDisable(u8 Copy_u8SegmentID);

ES_T SEV_SEG_enumSEGClear(u8 Copy_u8SegmentID);

#endif /* INCLUDE_HAL_SEVEN_SEGMENT_SEV_SEG_INT_H_ */
