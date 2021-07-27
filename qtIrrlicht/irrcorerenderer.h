
//irrcorerenderer.h

#ifndef IRRCORERENDER_H
#define IRRCORERENDER_H

#include <QObject>
#include <QWidget>
#include <irrlicht.h>

#include "CIrrRocketGUI.h"

using namespace irr;

class IrrCoreRenderer : public QWidget
{
    Q_OBJECT

public:
    IrrCoreRenderer(QWidget *irrRenderTarget, bool softwareRenderer);
    ~IrrCoreRenderer();
    void init();
    void resizeIrrWidget(int x, int y, int newWidth, int newHeight);
    CIrrRocketGUI *gui;

        irr::scene::ISceneNode* node;
        SIrrlichtCreationParameters params;


        virtual void timerEvent(QTimerEvent* event);
            IrrlichtDevice* device;
int renderthis();

private:
    QWidget *irrRenderTarget;
    video::E_DRIVER_TYPE rendererType;

protected:

};

#endif // IRRCORERENDER_H
