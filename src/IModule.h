//
// Created by Charles on 11/29/2020.
//

#ifndef MINIENGINE_IMODULE_H
#define MINIENGINE_IMODULE_H

class IModule {
public:
    virtual void Init() {};

    virtual void Update() {};

    virtual void OnWindowResize() {};

    virtual void Draw() {};

    virtual void Destroy() {};

    virtual ~IModule() {};
};

#endif //MINIENGINE_IMODULE_H
