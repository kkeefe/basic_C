void hist_builder(){


  std:: string input;
  ifstream myfile;

  //figure out which file it is you want to open
  std:: cout << "please enter the name of the file you want to open: " << std::endl;
  std:: cin >> input;

  //open the file
  myfile.open(input, std::ios::app);
  
  // I create a histogram with 10 steps with all the values between 0 and 1
  //the histogram uses the following format:
  //("name of histogram", "title of histogram", # of steps, lowest value, highest value)


  TH1D* my_hist = new TH1D("A Name", "A Title", 10, 0, 1);

    // I want to have 1000 entries in my histogram
    for (int i = 0; i < 1000; i++) {
      // this is where I insert values into my histogram
      my_hist->Fill(f()); 
    }

  // and lastly I draw it
  my_hist->Draw("hist")


}
