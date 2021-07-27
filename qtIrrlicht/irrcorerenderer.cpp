
//irrcorerenderer.cpp


#include "irrcorerenderer.h"




#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif



IrrCoreRenderer::IrrCoreRenderer(QWidget *irrRenderTarget, bool softwareRenderer)
{
    this->irrRenderTarget = irrRenderTarget;

    if(softwareRenderer)
    {
       this->rendererType = video::EDT_BURNINGSVIDEO;
    } else
    {
        this->rendererType = video::EDT_OPENGL;
    }

#ifdef __EMSCRIPTEN__
  //  device = irr::createDevice(irr::video::EDT_OGLES2, irr::core::dimension2d<irr::u32>(1024,768));
#else
  //  device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1024,768));
#endif

    //Set Parameters. Most important part here is: params.WindowId. This value sets the output destination of this Irrlicht instance.
    this->params.AntiAlias = 0;
    this->params.Bits = 32;
    this->params.DeviceType = EIDT_X11;
    this->params.Doublebuffer = true;
    this->params.DriverType = rendererType;
    this->params.EventReceiver = 0;
    this->params.Fullscreen = false;
    this->params.HighPrecisionFPU = false;
    this->params.IgnoreInput = false;
    this->params.LoggingLevel = ELL_INFORMATION;
    this->params.Stencilbuffer = true;
    this->params.Stereobuffer = false;
    this->params.Vsync = false;
    this->params.WindowId = reinterpret_cast<void*>(this->irrRenderTarget->winId());
    this->params.WindowSize.Width = this->irrRenderTarget->size().width();
    this->params.WindowSize.Height = this->irrRenderTarget->size().height();
    this->params.WithAlphaChannel = false;
    this->params.ZBufferBits = 16;

    this->device = createDeviceEx(this->params);

        CIrrRocketGUI gui2(this->device);
                gui=&gui2;
}

IrrCoreRenderer::~IrrCoreRenderer()
{
    this->device->drop();
}

void IrrCoreRenderer::init()
{
    if (this->device != 0)
    {
        scene::ISceneManager* smgr = this->device->getSceneManager();

     //   scene::ISceneNode* n = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./media/sydney.md2"));

      //  n->setMaterialTexture(0, this->device->getVideoDriver()->getTexture("./media/sydney.bmp"));
        //n->setMaterialFlag( video::EMF_LIGHTING, false );
    //    smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));

//        this->device->getFileSystem()->addFileArchive("media/map-20kdm2.pk3");

//        scene::IAnimatedMesh* mesh = smgr->getMesh("20kdm2.bsp");
//        scene::ISceneNode* node = 0;

//        if (mesh)
//        {
//            node = smgr->addOctreeSceneNode(mesh->getMesh(0), 0, -1, 1024);
//        }

//        if (node)
//        {
//            node->setPosition(core::vector3df(-1300, -144, -1299));
//        }

 node = smgr->addCubeSceneNode(10);



        smgr->addCameraSceneNode();




        startTimer(0);
    }
}


irr::core::rect<irr::s32> getOnScreenRect(irr::scene::ISceneNode* node, irr::scene::ISceneCollisionManager* csmgr)
{
    irr::core::aabbox3df box = node->getTransformedBoundingBox();

    irr::core::vector3df vec[8];
    box.getEdges(vec);

    irr::core::array<irr::core::vector2di> spos;
    for (int i=0; i<8; i++)
        spos.push_back(csmgr->getScreenCoordinatesFrom3DPosition(vec[i]));

    irr::core::rect<irr::s32> b(spos[0], spos[0]);
    for (int i=0; i<8; i++)
        b.addInternalPoint(spos[i]);
    return b;
}

void IrrCoreRenderer::timerEvent(QTimerEvent* event)
{
    if(this->device != 0)
    {
        this->device->getTimer()->tick();

        video::SColor color (255, 100, 100, 140);
        this->device->getVideoDriver()->beginScene(true, true, color);
        this->device->getSceneManager()->drawAll();

renderthis();

        this->device->getVideoDriver()->endScene();

    }
    else
        device->yield();
}

int IrrCoreRenderer::renderthis(){
irr::video::SMaterial mat;
mat.Lighting = false;
this->device->getVideoDriver()->setMaterial(mat);
this->device->getVideoDriver()->setTransform(irr::video::ETS_WORLD, irr::core::IdentityMatrix);
{
    irr::core::vector3df p1(-20,0,-10);
    irr::core::vector3df p2(-20,0,10);
    irr::core::vector3df p3(20,0,10);
    irr::core::vector3df p4(20,0,-10);

    irr::core::matrix4 mat;
    irr::core::vector3df rot = this->device->getSceneManager()->getActiveCamera()->getRotation();
    rot.X = 0;
    rot.Z = 0;
    mat.setRotationDegrees(rot);


    irr::core::line3df ray = this->device->getSceneManager()->getSceneCollisionManager()->getRayFromScreenCoordinates(irr::core::vector2di(512, 384));
    irr::core::plane3df plane(irr::core::vector3df(0), irr::core::vector3df(0,1,0));
    irr::core::vector3df out;
    if (plane.getIntersectionWithLine(ray.start, ray.getVector(), out))
    {
        mat.setTranslation(out);

        mat.transformVect(p1);
        mat.transformVect(p2);
        mat.transformVect(p3);
        mat.transformVect(p4);

        irr::core::triangle3df t1(p1, p2, p3);
        irr::core::triangle3df t2(p3, p4, p1);

        this->device->getVideoDriver()->draw3DTriangle(t1);
        this->device->getVideoDriver()->draw3DTriangle(t2);

        irr::core::aabbox3df box = node->getTransformedBoundingBox();

        irr::core::rect<irr::s32> b = getOnScreenRect(node, this->device->getSceneManager()->getSceneCollisionManager());

        this->device->getVideoDriver()->draw3DBox(box);

        this->device->getVideoDriver()->draw2DRectangleOutline(b);
    }
}

 gui->run();

}

void IrrCoreRenderer::resizeIrrWidget(int x, int y, int newWidth, int newHeight)
{
    //Resize the render target widget which shows the Irrlicht output.
    this->irrRenderTarget->setGeometry(x, y, newWidth, newHeight);

    //Resize Irrlicht render output itself
    if(this->device != 0)
    {
        core::dimension2d<u32> widgetSize;
        widgetSize.Width = newWidth;
        widgetSize.Height = newHeight;

        this->device->getVideoDriver()->OnResize(widgetSize);

        scene::ICameraSceneNode *cam = this->device->getSceneManager()->getActiveCamera();
        if (cam != 0)
        {
            cam->setAspectRatio((f32)widgetSize.Width / (f32)widgetSize.Height);

        }
    }
}
