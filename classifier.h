#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

class GNB {
public:

	vector<string> possible_labels = {"left","keep","right"};

    vector<vector<double>> mean = {{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0}};
    vector<vector<double>> std = {{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0}};
    vector<float> count_labels={0.0,0.0,0.0};
    vector<double> class_prob={0.0,0.0,0.0};
	/**
  	* Constructor
  	*/
 	GNB();

	/**
 	* Destructor
 	*/
 	virtual ~GNB();

 	void train(vector<vector<double> > data, vector<string>  labels);

  	string predict(vector<double>);
  	
  	double prob_product(vector<double> data,int k);
    double gaussian(double data, double sigma,double mean);
};

#endif



