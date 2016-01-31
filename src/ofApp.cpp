#include "ofApp.h"

void nebulaEye::setup()
{
  video.setup();
  flow.setup();
  bgSub.setup();
  contour.setup();
  zone.setup();

  gui.setup("nebula-eye","settings.xml",660,10);
  gui.add(video.guiGrp);
  gui.add(bgSub.guiGrp);
  gui.add(flow.guiGrp);
  gui.add(contour.guiGrp);
  gui.add(zone.guiGrp);

  gui.loadFromFile("settings.xml");

  ofAddListener(gui.savePressedE, &bgSub, &nebulaBackground::saveAlgoParam);

  ofSetCircleResolution(100);

  ofSetBackgroundColor(0);
}

void nebulaEye::update()
{
  video.update();
  if(video.isFrameNew()){
    auto img = video.getPixels();
    bgSub.update(img);
    flow.update(img);
    contour.update(bgSub.m_fgmask);
  }
}

void nebulaEye::draw()
{
  video.draw(0,0,640,480);
  bgSub.draw(640,0,640,480);
  flow.draw(0,480, 640, 480);
  contour.draw(0,0,640,480);

  zone.draw();
  gui.draw();
}

void nebulaEye::exit()
{
}

void nebulaEye::mouseMoved(ofMouseEventArgs& mouse)
{
}

void nebulaEye::mouseDragged(ofMouseEventArgs& mouse)
{
}

void nebulaEye::mousePressed(ofMouseEventArgs& mouse)
{
}

void nebulaEye::mouseReleased(ofMouseEventArgs& mouse)
{
}

void nebulaEye::mouseScrolled(ofMouseEventArgs& mouse)
{
}

void nebulaEye::mouseEntered(ofMouseEventArgs& mouse)
{
}

void nebulaEye::mouseExited(ofMouseEventArgs& mouse)
{
}
