#include<iostream>
#include<stdlib.h>
using namespace std;
class patient{
		public:
				int patientID;
				string Pname;
				
				void getPatientInfo();
				void putPatientInfo();
				void makeAppointment();
				void Diagnosis();
				void Billing();
				void printBill ();

		private:
				string Address, Gender, Blood_Group, doctor_Name, app_date, DiagnosisInfo, MedicineInfo;
				int    doctorFee, Phone, medicine_charge, Total;
				
};

void patient ::	getPatientInfo()
{
	cout<<"Enter patient Name: ";
	cin>>Pname;
	cout<<"Enter patient ID: ";
	cin>>patientID;
	cout<<"Enter patient Address: ";
	cin>>Address;
	cout<<"Enter patient Phone number: ";
	cin>>Phone;
	cout<<"Enter patient Blood Group: ";
	cin>>Blood_Group;
}

void patient :: putPatientInfo()
{
	cout<<"\nPATIENT INFO: ";
	cout<<"\nPatient name: "<<Pname;
	cout<<"\nPatient ID: "<<patientID;
	cout<<"\nPatient address: "<<Address;
	cout<<"\nPatient phone number: "<<Phone;
	cout<<"\nPatient Blood Group: "<<Blood_Group<<"\n";
}

void patient :: makeAppointment()
{
	
	cout<<"Enter Doctor Name: ";
	cin>>doctor_Name;
	cout<<"Enter Appointment Date: ";
	cin>>app_date;
}

void patient :: Diagnosis()
{
	cout<<"Enter Diagnosis Info: ";
	cin>>DiagnosisInfo;
	cout<<"Enter Medicine Info: ";
	cin>>MedicineInfo;	
}

void patient :: Billing()
{
	cout<<"Enter Doctor Fee: ";
	cin>>doctorFee;
	cout<<"Enter Medicine Charge: ";
	cin>>medicine_charge;
	Total = doctorFee + medicine_charge;
}

void patient :: printBill()
{
	cout<<"\n************************************\n";
	cout<<"PATIENT INFO: ";
	cout<<"\n\nPatient name: "<<Pname;
	cout<<"\nPatient ID: "<<patientID;
	cout<<"\nPatient address: "<<Address;
	cout<<"\nPatient phone number: "<<Phone;
	cout<<"\nPatient Blood Group: "<<Blood_Group<<"\n";
	cout<<"************************************\n\n";
	cout<<"************************************\n";
	cout<<"APPOINTMENT DETAILS: ";
	cout<<"\n\nDoctor Name: "<<doctor_Name;
	cout<<"\nAppointment Date: "<<app_date;
	cout<<"\n************************************\n";
	cout<<"\n************************************\n";
	cout<<"DIAGNOSIS DETAILS AND MEDICINE: ";
	cout<<"\n\nDiagnosis info: "<<DiagnosisInfo;
	cout<<"\nMedicine info: "<<MedicineInfo;
	cout<<"\n************************************\n";
	cout<<"\n************************************\n";
	cout<<"BILL: ";
	cout<<"\n\nDoctor's Fee: "<<doctorFee;
	cout<<"\nMedicine Charge: "<<medicine_charge;
	cout<<"\nTOTAL CHARGE: "<<Total;
	cout<<"\n************************************\n";

}
	

int main()
{
	cout<<"MENU:-\n\n1. getPatientInfo\n2. putPatientInfo\n3. makeAppointment\n4. Diagnosis\n5. Billing\n6. printBill\n7. EXIT\n\n";
	int ch;
	patient obj;
	while(1)
	{
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:{
				obj.getPatientInfo();
				break;
			}
		
			case 2:{
				obj.putPatientInfo();
				break;
			}
			case 3:{
				obj.makeAppointment();
				break;
			}
			case 4:{
				obj.Diagnosis();
				break;
			}
			case 5:{
				obj.Billing();
				break;
			}
			case 6:{
				obj.printBill();
				break;
			}
			case 7:{
				cout<<"\nTHANKYOU:)\n";
				exit(0);
			}
			default:{
				cout<<"INVALID CHOICE: \n";
				break;
			}
			
		}
	}
}




