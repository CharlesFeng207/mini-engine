//
// Created by Charles on 11/29/2020.
//

#ifndef MINIENGINE_GUIDEMO_H
#define MINIENGINE_GUIDEMO_H

#include "../IModule.h"
#include <imgui/imgui.h>

class GUIDemo : public IModule {
public:
    virtual void Init();

    virtual void Update();

    virtual void OnWindowResize();

    virtual void Draw();

    virtual void Destroy();

    virtual ~GUIDemo();

private:
    bool show_demo_window;
    bool show_another_window;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};

#endif //MINIENGINE_GUIDEMO_H
