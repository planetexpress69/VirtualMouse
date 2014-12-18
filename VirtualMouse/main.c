//
//  main.c
//  VirtualMouse
//
//  Created by Martin Kautz on 18.12.14.
//  Copyright (c) 2014 JAKOTA Design Group. All rights reserved.
//

#include <ApplicationServices/ApplicationServices.h>

int main(int argc, const char * argv[]) {

    if (argc != 5) {
        printf ("Usage: mouse2 strtX strtY endX endY!\n");
        exit(1);
    }

    int strtX = atoi(argv[1]);
    int strtY = atoi(argv[2]);
    int stopX = atoi(argv[3]);
    int stopY = atoi(argv[4]);

    int x;
    int y;

    sleep(5); // time to get the window with the picture in it

    CGEventRef move = NULL;

    for (y = strtY; y < stopY; y ++) {
        for (x = strtX; x < stopX; x ++) {
            move = CGEventCreateMouseEvent(
                                           NULL,
                                           kCGEventMouseMoved,
                                           CGPointMake(x, y),
                                           kCGMouseButtonLeft);
            CGEventPost(kCGHIDEventTap, move);
            CFRelease(move);
            usleep(500000); // sleep for half a second to give the JavaScript some time...
        }
    }

    exit (0);
}

