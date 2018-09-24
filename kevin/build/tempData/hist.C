{
  c1 = new TCanvas("c1", "ntuples", 1000, 500);
  c1->SetGrid();
  c1->Divide(2,1);

  TFile* f = new TFile("pmma_ps.root", "pmma and ps");
  //get the ntuple you want

  TTree* ttree = (TTree*)f->Get("Ntuple3");
  cout << "Working.. "  << endl;

  gStyle->SetOptStat(111111);

  int counts = ttree->GetEntries();
  fX_hist = new TH1I("fX_pos", "X Position Distribution", 100, -50, 50);
  fY_hist = new TH1I("fY_pos", "Y Position Distribution", 100, -50, 50);
  
  double fX_pos, fY_pos;
  ttree->SetBranchAddress("fX_pos",&fX_pos);
  ttree->SetBranchAddress("fY_pos",&fY_pos);
  
  for(int i = 0; i < counts; i++){
    ttree->GetEntry(i);
    fX_hist->Fill(fX_pos);
    fY_hist->Fill(fY_pos);    
  }

  c1->cd(1);
  fX_hist->Draw();

  c1->cd(2);
  fY_hist->Draw();
  
}
