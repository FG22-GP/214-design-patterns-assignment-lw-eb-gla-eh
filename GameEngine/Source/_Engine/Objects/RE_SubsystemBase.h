#pragma once

class RE_SubsystemBase {
public:
    virtual void FixedUpdate(float DeltaTime) = 0;

    virtual ~RE_SubsystemBase(){}
};
