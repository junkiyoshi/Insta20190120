#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(239);
	ofSetLineWidth(3);
	ofEnableDepthTest();

	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int len = 500;
	for (int i = 0; i < 2; i++) {

		for (int z = -len * 0.5; z <= len * 0.5; z += 30) {

			int param_start = ofGetFrameNum() + (z + len * 0.5) * 0.1;
			vector<glm::vec3> vertices;
			vector<glm::vec3> sub_vertices;
			for (int param = param_start; param <= param_start + 30; param++) {

				vertices.push_back(glm::vec3(this->make_point(len, param), z - 15));
				sub_vertices.push_back(glm::vec3(this->make_point(len, param), z + 15));
			}

			for (int i = sub_vertices.size() - 1; i > -1; i--) {

				vertices.push_back(sub_vertices[i]);
			}

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);
		}

		ofRotateX(90);
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}