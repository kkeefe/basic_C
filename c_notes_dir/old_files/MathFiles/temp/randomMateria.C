{
  double prob;
  cout << "please input the probability of the event: " << endl;
  cin >> prob;
  double slots;
  cout << "please input the number of slots you will try for: " << endl;
  cin >> slots;

  double totalSuccess = 0, totalTries = 0, totalFails = 0;
  
  //repeat this until you get 100,000 successes per slot
  for(int j = 0; j < 100000; ++j){
  //define initial starting values.
  double success = 0, tries = 0, fails = 0;

  //do the whole loop for each slot
  for(int i = 0; i < slots; ++i)
    {
      bool meld = false;
      //for each single attempt
      while(!meld){
	double chance;
	//define a random number between 0 and 100
	chance = gRandom->Uniform(0, 100);
	if(chance <= prob){
	  //add one to success each time
	  meld = true;
	  success += 1;
	}else if(chance > prob){
	  fails += 1;
	}
	//add one to tries each time
	tries += 1;
      }
    }
  totalSuccess += success;
  totalTries += tries;
  totalFails += fails;
  }

  cout << totalTries << " is the number of times you tried " << endl;
  cout << totalSuccess << " is the number of times you succeeded " << endl;
  cout << totalFails << " is the number of times you failed " << endl;
  cout << totalTries/totalSuccess << " is your try to succeed ratio" << endl;  
}
