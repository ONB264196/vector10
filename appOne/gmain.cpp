#include"libOne.h"
void gmain() {
    window(1000, 1000);
    angleMode(DEGREES);
    float ax, ay, aAngle = -15;
    float bx, by, bAngle = 30;
    float incDeg = 15;
    float dp, cp;
    float angleBetween;
    
    while (notQuit) {
        clear(0, 40, 0);
        mathAxis(1.5f, 200);

        if (isTrigger(KEY_A))aAngle += incDeg;
        if (isTrigger(KEY_D))aAngle -= incDeg;
        ax = cos(aAngle);
        ay = sin(aAngle);
        if (isTrigger(KEY_LEFT))bAngle += incDeg;
        if (isTrigger(KEY_RIGHT))bAngle -= incDeg;
        bx = cos(bAngle);
        by = sin(bAngle);

        if (isPress(MOUSE_LBUTTON)) {
            bx = mathMouseX;
            by = mathMouseY;
        }

        dp = ax * bx + ay * by;
        cp = ax * by - ay * bx;
        angleBetween = atan2(cp, dp);

        strokeWeight(10);
        stroke(255);
        mathArrow(0, 0, ax, ay);
        stroke(128);
        mathArrow(0, 0, bx, by);

        float cx = ax * dp;
        float cy = ay * dp;
        stroke(255, 200, 200);
        mathLine(0, 0, cx, cy);
        float dx = -ay *cp;
        float dy = ax * cp;
        stroke(10, 200, 255);
        mathLine(cx, cy, cx + dx, cy + dy);

        stroke(255, 255, 200);
        mathArc(aAngle, angleBetween, 0.1f);

        textSize(50);
        fill(160, 200, 255);
        text((let)"  dot: ax*by+ay*bx=" + dp, 0, 50);
        fill(255, 200, 200);
        text((let)"cross: ax*bx+ay*by=" + cp, 0, 100);
        fill(255, 255, 200);
        text((let)"atan2(cross,dot)=" + round(angleBetween), 0, 150);

    }
}