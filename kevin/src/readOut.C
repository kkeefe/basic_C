{
  string fileName;
  cout << "Please input the name of the file you want to check for PMMA vs PS:\t";
  cin >> fileName;
  
  ifstream infile(fileName);
  ofstream outfile(fileName + ".bk");
  
  //make sure the file opens
  if(infile){
    while(!infile.eof()){
      int a;
      infile >> a;
      if(a){
	cout << "PMMA\t";
	outfile << "PMMA\t";
      }else
	cout << "PS\t";
	outfile << "PS\t";      
    }
  }else{
    cerr << "file did not open correctly." << endl;
  }
   
  infile.close();
  outfile.close();
}
