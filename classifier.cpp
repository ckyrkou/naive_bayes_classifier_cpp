#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <vector>
#include "classifier.h"

/**
 * Initializes GNB
 */
GNB::GNB() {

}

GNB::~GNB() {}

void GNB::train(vector<vector<double>> data, vector<string> labels)
{


	/*
		Trains the classifier with N data points and labels.

		INPUTS
		data - array of N observations
		  - Each observation is a tuple with 4 values: s, d, 
		    s_dot and d_dot.
		  - Example : [
			  	[3.5, 0.1, 5.9, -0.02],
			  	[8.0, -0.3, 3.0, 2.2],
			  	...
		  	]

		labels - array of N labels
		  - Each label is one of "left", "keep", or "right".
	*/
	
	    int k;
	    
	    
    	for(int i=0;i<data.size();i++){
    	    
    	    if(labels[i] == "left"){
    	            k=0;
    	        }
    	        if(labels[i] == "keep"){
    	            k=1;
    	        }
    	        if(labels[i] == "right"){
    	            k=2;
    	        }
    	        
    	        count_labels[k]+=1;
   
    	    for(int j=0;j<4;j++){
    	        mean[k][j] +=  data[i][j];
    	    }
    	}
    	
    	for(int z=0;z<3;z++){
    	    for(int j=0;j<4;j++){
    	        mean[z][j] /=  count_labels[z];
    	    }
    	    
    	}    
    	
    	
    	for(int i=0;i<data.size();i++){
    	    
    	    if(labels[i] == "left"){
    	            k=0;
    	        }
    	        if(labels[i] == "keep"){
    	            k=1;
    	        }
    	        if(labels[i] == "right"){
    	            k=2;
    	        }

    	    for(int j=0;j<4;j++){
    	        std[k][j] +=  pow(data[i][j]-mean[k][j],2);
    	    }
    	}
    	
    	for(int z=0;z<3;z++){
    	    for(int j=0;j<4;j++){
    	        std[z][j] = sqrt(std[z][j]/count_labels[z]);
    	    }
    	}   
	
	    for(int z=0;z<3;z++){
	        std::cout << "Class: " << z << " has " << count_labels[z] << " samples" << std::endl;
	        std::cout << "Mean: ";
    	    for(int j=0;j<4;j++){
    	        std::cout << mean[z][j] << " ";
    	    }
    	    std::cout << std::endl;
    	    std::cout << "Std: ";
    	    for(int j=0;j<4;j++){
    	        std::cout << std[z][j] << " ";
    	    }
    	    std::cout << std::endl;
    	    class_prob[z] = count_labels[z]/data.size();
    	    std::cout << "Class Probability: " << class_prob[z] << std::endl;
    	}
	
	    //std::cout << "Mean: " << z <<mean[z][j] << std::endl;
	    
	    //std::cout << "Std: " << z << std[z][j] << std::endl;

	
}

double GNB::gaussian(double data, double sigma,double mean){
    
    return (1.0/(2.0*M_PI*(pow(sigma,2.0))))*exp(-(pow((data-mean),2.0))/(2.0*(pow(sigma,2.0))));
    
    
}

double GNB::prob_product(vector<double> data,int k){
    
    double prob_prod=1.0;
    
    for(int i=0;i<data.size();i++){
        
       prob_prod*=GNB::gaussian(data[i],std[k][i],mean[k][i]);
        
    }
    return prob_prod;
    
    
}


string GNB::predict(vector<double> sample)
{
	/*
		Once trained, this method is called and expected to return 
		a predicted behavior for the given observation.

		INPUTS

		observation - a 4 tuple with s, d, s_dot, d_dot.
		  - Example: [3.5, 0.1, 8.5, -0.2]

		OUTPUT

		A label representing the best guess of the classifier. Can
		be one of "left", "keep" or "right".
		"""
		# TODO - complete this
	*/
	double belief=0.0,p=0.0;
	string class_label;
	for (int i=0;i<3;i++){
	    p=GNB::prob_product(sample,i);
	    if(p >= belief){
	        belief=p;
	        class_label = possible_labels[i];
	    }
	}
	
	

    

	return class_label;

}