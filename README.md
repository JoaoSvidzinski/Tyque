
<p align="center">
  <h1 align="center">Tyque</h1>
  <p align="center">
    João Svidzinski piece for clarinet and live electronics
  </p>
</p>


# Equipment list

- [Max 8](https://cycling74.com/products/max)
- [Hoa library](https://hoalibrary.mshparisnord.fr/)
- 2 microphones
- 8 speakers


# Instructions

- Compile .mxo Faust code (see below)
- Install Hoa Library
- Install Patch (see below)


## Patch installation

1. Download or clone *Patch_concert_2018*
2. In *Max 8*, choose *.../Patch_concert_2018* in *option* > *File preferences*
3. Check the *Audio status* in *option > Audio Status*:
4. Close max and open *_Tyque2019_Concert.maxpat&nbsp;*(red label)

## Faust compilation

1. Download the Faust code *jgrain3.dsp*, *jgrain7.dsp* and *mTDelHarmo7B~.dsp*
2. In Faust IDE [web site](https://faustide.grame.fr/) drag and drop the .dsp files.
4. Run de code and export it (small yellow button). Choose the plateform (osx for max) and the Architecture (max).
5. Download it and put the .mxo files in the main folder (*.../Patch_concert_2018*)

## Audio Setup

Sampling rate = 48000
I/O Vector Size = 512
Signal Vector Size = 256
Scheduler in Overdrive X

## Initialisation routine

1. Configure audio status (see DSP status above).
2. Turn on the DSP
3. Set the direct sound sound level
4. Trigger the events to start (using the keyboard space key) following the score.

## More informations

 - http://archiverlepresent.org/fiche-de-la-collection/tyche
 - https://hal.archives-ouvertes.fr/tel-02045765/document
