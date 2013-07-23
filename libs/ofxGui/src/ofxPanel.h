#pragma once

#include "ofxBaseGui.h"
#include "ofConstants.h"
#include "ofxXmlSettings.h"
#include "ofxSlider.h"
#include "ofxButton.h"
#include "ofxToggle.h"
#include "ofRectangle.h"
#include "ofImage.h"


class ofxPanel : public ofxBaseGui{
public:
	ofxPanel();

	virtual ~ofxPanel();
	
	ofxPanel * setup(string collectionName="", string _filename="", float x = 10, float y = 10);
	
	virtual void load();
	virtual void save();

	virtual void saveToXml(ofxXmlSettings& xml);
	virtual void loadFromXml(ofxXmlSettings& xml);
	
	void add(ofxBaseGui * element);
	void add(ofxParameter<float> & parameter);
	void add(ofxParameter<int> & parameter);
	void add(ofxParameter<bool> & parameter);
	
	void clear();
	
	virtual void mouseMoved(ofMouseEventArgs & args);
	virtual void mousePressed(ofMouseEventArgs & args);
	virtual void mouseDragged(ofMouseEventArgs & args);
	virtual void mouseReleased(ofMouseEventArgs & args);
	
	void draw();
	
	vector<string> getControlNames();
	int getNumControls();

	ofxIntSlider getIntSlider(string name);
	ofxFloatSlider getFloatSlider(string name);
	ofxToggle getToggle(string name);
	ofxButton getButton(string name);

	ofxBaseGui * getControl(string name);
	ofxBaseGui * getControl(int num);

protected:
	void setValue(float mx, float my, bool bCheck);

	template<class ControlType>
	ControlType getControlType(string name);

	void fold() { bCollectionVisible = !bCollectionVisible; }

protected:
	ofPoint grabPt;
	bool bGrabbed;
	bool bCollectionVisible;
	float spacing;
	float header;
	vector <ofxBaseGui *> collection;
	
	string filename;
	ofRectangle foldBox, loadBox, saveBox;
	static ofImage foldIcon, loadIcon, saveIcon;
};

template<class ControlType>
ControlType ofxPanel::getControlType(string name){
	ControlType * control = dynamic_cast<ControlType*>(getControl(name));
	if(control) return *control;
	else return ControlType();
}
