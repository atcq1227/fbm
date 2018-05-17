#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    w = 2000;
    h = 1500;
    
    ofSetWindowShape(w, h);
    
    fboA.allocate(w, h);
    fboB.allocate(w, h);
    curr = &fboA;
    prev = &fboB;

	//	make our mesh
	vector<ofVec3f> vertices;
	vector<ofVec2f> uvs;
	vector<ofIndexType> indices;

	vertices.push_back( ofVec3f(-1,-1,0) );
	vertices.push_back( ofVec3f(-1, 1,0) );
	vertices.push_back( ofVec3f( 1, 1,0) );
	vertices.push_back( ofVec3f( 1,-1,0) );

	uvs.push_back( ofVec2f(0,0) );
	uvs.push_back( ofVec2f(0, 1) );
	uvs.push_back( ofVec2f( 1, 1) );
	uvs.push_back( ofVec2f( 1,0) );

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	indices.push_back(0);
	indices.push_back(2);
	indices.push_back(3);

	plane.addVertices( vertices );
	plane.addTexCoords( uvs );
	plane.addIndices( indices );
    
    ofDirectory dir("sounds");
    dir.listDir();
    dir.sort();
    
    //go through and print out all the paths
    for(int i = 0; i < dir.size(); i++){
        soundFiles.push_back(dir.getPath(i));
    }
    
    sound.load(soundFiles[0]);
    sound.play();
    sound.setLoop(true);

	//	load our shader
    shader.load("shaders/fbm.vert", "shaders/fbm.frag");
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    time = ofGetElapsedTimef();
    
    curr->begin();
    
	shader.begin();
	
    shader.setUniformTexture("tex", *prev, 0);
    shader.setUniform2f( "u_resolution", prev->getWidth(), prev->getHeight());
    shader.setUniform2f( "time", time, time);
    

	plane.draw();

	shader.end();
    
    curr->end();
    
    curr->draw(0, 0, w, h);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
