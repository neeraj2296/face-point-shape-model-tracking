/*
 * face_tracker.h
 *
 *  Created on: 2016/1/17
 *      Author: lincoln
 */

#ifndef FACE_TRACKER_H_
#define FACE_TRACKER_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "fd.h"

#define FEATURE_POINTS_NUMBER 24
#define SUB_SPACE_DIM 8 //4 rigid, 4 non-rigid
#define CLAMP_FACTOR 3.0
#define PATCH_SIZE 11
#define FACE_TRACKING_RESET_COUNT_TRESHOLD 8
#define FACE_TRACKING_RESET_COUNT_BORDER 10

typedef struct
    {
	//patch searching area sizes
	unsigned char search_size[2];
	//true for on track status, false for re-detection needed
	bool isTracking;
	point_2f64_lincoln feature_points[FEATURE_POINTS_NUMBER];
	//the model variation corresponding coefficients
	double p[SUB_SPACE_DIM];
	//template matching result (score)
	double match_responses[FEATURE_POINTS_NUMBER];
	//count to set isTracking flag down
	unsigned char track_reset_count;
    }face_tracker_params;

void face_track
    (
    const unsigned char* src
    );

void draw_ft_result
    (
    unsigned char* src
    );

void init_face_tracker
    (
    void
    );

void free_face_tracker
    (
    void
    );

#ifdef __cplusplus
}
#endif
#endif /* FACE_TRACKER_H_ */
