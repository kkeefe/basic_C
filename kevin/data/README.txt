A:

  mirrorCoating->SetType(dielectric_dielectric);
  mirrorCoating->SetFinish(polished);
  mirrorCoating->SetModel(unified);

  // create material properties table for silver coating
  G4MaterialPropertiesTable* SMPT = new G4MaterialPropertiesTable();

  // reflectivity, and RINDEX
  // G4double REFLECTIVITY[] = {0.975, 0.975};

  // add properties
  // SMPT->AddProperty("REFLECTIVITY", energyRange, REFLECTIVITY, 2)->SetSpline(true);

  // create MPT for mirror coating
  mirrorCoating->SetMaterialPropertiesTable(SMPT);


B:

  mirrorCoating->SetType(dielectric_dielectric);
  mirrorCoating->SetFinish(polished);
  mirrorCoating->SetModel(unified);

  // create material properties table for silver coating
  G4MaterialPropertiesTable* SMPT = new G4MaterialPropertiesTable();

  // reflectivity, and RINDEX
  G4double REFLECTIVITY[] = {0.975, 0.975};

  // add properties
  SMPT->AddProperty("REFLECTIVITY", energyRange, REFLECTIVITY, 2)->SetSpline(true);


C:

  mirrorCoating->SetType(dielectric_metal);
  mirrorCoating->SetFinish(polished);
  mirrorCoating->SetModel(unified);

  // create material properties table for silver coating
  G4MaterialPropertiesTable* SMPT = new G4MaterialPropertiesTable();

  // reflectivity, and RINDEX
  // G4double REFLECTIVITY[] = {0.975, 0.975};

  // add properties
  // SMPT->AddProperty("REFLECTIVITY", energyRange, REFLECTIVITY, 2)->SetSpline(true);


D:

  mirrorCoating->SetType(dielectric_metal);
  mirrorCoating->SetFinish(polished);
  mirrorCoating->SetModel(unified);

  // create material properties table for silver coating
  G4MaterialPropertiesTable* SMPT = new G4MaterialPropertiesTable();

  // reflectivity, and RINDEX
  G4double REFLECTIVITY[] = {0.975, 0.975};

  // add properties
  SMPT->AddProperty("REFLECTIVITY", energyRange, REFLECTIVITY, 2)->SetSpline(true);


E:

  mirrorCoating->SetType(dielectric_dielectric);
  mirrorCoating->SetFinish(polishedfrontpainted);
  mirrorCoating->SetModel(unified);

  // create material properties table for silver coating
  G4MaterialPropertiesTable* SMPT = new G4MaterialPropertiesTable();

  // reflectivity, and RINDEX
  G4double REFLECTIVITY[] = {0.975, 0.975};

  // add properties
  SMPT->AddProperty("REFLECTIVITY", energyRange, REFLECTIVITY, 2)->SetSpline(true);


F:

  mirrorCoating->SetType(dielectric_dielectric);
  mirrorCoating->SetFinish(polishedbackpainted);
  mirrorCoating->SetModel(unified);

  // create material properties table for silver coating
  G4MaterialPropertiesTable* SMPT = new G4MaterialPropertiesTable();

  // reflectivity, and RINDEX
  G4double REFLECTIVITY[] = {0.975, 0.975};

  // add properties
  SMPT->AddProperty("REFLECTIVITY", energyRange, REFLECTIVITY, 2)->SetSpline(true);
