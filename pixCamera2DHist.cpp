#include <iostream>

#include "TInterpreter.h"
#include "TString.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH2D.h"
#include "TROOT.h"
#include "TCanvas.h"

void pixCamera2DHist(const char * in_filename = nullptr)
{
    // TNtuple *ntup0 = (TNtuple *)gROOT->FindObject("ntup0");
    TH2I* th2d = new TH2I("h2","",8,-0.5,7.5,8,-0.5,7.5);
    th2d->GetXaxis()->SetTitle("pixel Row");
    th2d->GetYaxis()->SetTitle("pixel Col");

    // declare this bad boi for scope
    TNtuple* ntup0;
    //  if we're given a file name we assume we need to load it up and get ntup0 ourselves
    if(in_filename){
        std::cout << "loading the file: " << in_filename << std::endl;
        TFile *f = new TFile(in_filename);
        ntup0 = (TNtuple *)f->Get("ntup0");
    }else{
        const char* filename = gROOT->GetFile()->GetName();
        TFile *f = new TFile(filename);
        ntup0 = (TNtuple *)f->Get("ntup0");
    }

    // how many entries do we have:
    int nEntries = ntup0->GetEntries();

    // create the variables we want
    // ntuples absolutely require float values!
    float_t pixNum;
    float_t triggered;
    ntup0->SetBranchAddress("pixNum", &pixNum);
    ntup0->SetBranchAddress("triggered", &triggered);

    for(int i = 0; i < nEntries; ++i)
    {
        ntup0->GetEntry(i);
        // lets fill the TH2D if we've triggered
        if(triggered!=0)
        {
            // fill the rows and columns to match a SiPM..
            int barNum = int(pixNum); // cast out float as an int
            th2d->Fill(barNum/8,barNum%8);
        }

    }

    // picture things
    TCanvas *c1 = new TCanvas("c1", "Canvas name", 1650, 550);
    c1->Divide(3, 1);
    c1->cd(1);
    // we've filled it all of the way so lets draw it..
    // th2d->Draw("lego1");
    // gives a 2D surface to the top of the TH2D..
    th2d->Draw("surf1");
    //  gives 'pixel' like resolution weighting to the individual bins
    // th2d->Draw("box");
    c1->cd(2);
    th2d->Draw("text box"); // including the text option gives number of 'hits' within the bin

    c1->cd(3);
    th2d->Draw("lego1"); // including the text option gives number of 'hits' within the bin

    // file saving information
    const char* filename = gROOT->GetFile()->GetName();
    TString filesave = filename;
    filesave.Remove(filesave.Sizeof() - 6, 6);
    filesave = filesave + ".png";
    th2d->SaveAs(filesave);
}
