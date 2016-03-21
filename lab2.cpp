#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"classbmi.cpp"
using namespace std;

void create_data(){

	ofstream data1("file.in.txt", ios::out);
	data1<<"170 68"<<"\n"<<"160 85"<<"\n"<<"162 43"<<"\n"<<"167 80"<<"\n"<<"192 58"<<"\n"<<"0 0"<<endl;

}

void analyze_data(){
	
	int i,j;
	float BMI[6],array[6][2];
	
	ifstream data2("file.in.txt", ios::in);
	for(i=0;i<6;i++){
		for(j=0;j<2;j++){
			data2>>array[i][j];
		}
	}
	
	for(i=0;i<6;i++){
		bmi.height[i] = array[i][0]/100;
		bmi.weight[i] = array[i][1];
		BMI[i] = bmi.weight[i]/bmi.height[i]/bmi.height[i];
		//cout<<BMI[i]<<"\n";
	
		if(BMI[i]<15){
			ofstream data2("file.out.txt", ios::app);
			data2<<fixed<<setprecision(2)<<BMI[i]<<"  Very severely underweight"<<endl;
		}
		else if(BMI[i]>=15.0 && BMI[i]<16.0){
			ofstream data2("file.out.txt", ios::app);
			data2<<fixed<<setprecision(2)<<BMI[i]<<"  Severely underweight"<<endl;
		}
		else if(BMI[i]>=16.0 && BMI[i]<18.5){
			ofstream data2("file.out.txt", ios::app);
			data2<<fixed<<setprecision(2)<<BMI[i]<<"  Underweight"<<endl;
		}
		else if(BMI[i]>=18.5 && BMI[i]<25.0){
			ofstream data2("file.out.txt", ios::app);
			data2<<fixed<<setprecision(2)<<BMI[i]<<"  Normal"<<endl;
		}
		else if(BMI[i]>=25.0 && BMI[i]<30.0){
			ofstream data2("file.out.txt", ios::app);
			data2<<fixed<<setprecision(2)<<BMI[i]<<"  Overweight"<<endl;
		}
		else if(BMI[i]>=30.0 && BMI[i]<35.0){
			ofstream data2("file.out.txt", ios::app);
			data2<<fixed<<setprecision(2)<<BMI[i]<<"  Obese Class I (Moderately obese)"<<endl;
		}
		else if(BMI[i]>=35.0 && BMI[i]<40.0){
			ofstream data2("file.out.txt", ios::app);
			data2<<fixed<<setprecision(2)<<BMI[i]<<"  Obese Class II (Severely obese)"<<endl;
		}else if(BMI[i]>=40.0){
			ofstream data2("file.out.txt", ios::app);
			data2<<fixed<<setprecision(2)<<BMI[i]<<"  Obese Class III (Very severely obese)"<<endl;
		}
	}
	
}


int main(){
	create_data();
	analyze_data();
	
	return 0;
}
