#include <stdio.h>
#include "musictheory.h"

int main(void) {
    Note scbase[8];
    Scale cmajor = getScale((Note) {C, NONE, 4}, &NATURAL_MIN_SCALE, scbase, DESCEND);
    printf("Major Scale and Chord of each note of the C4 minor scale, descending, along with its frequency and wavelength\n\n");

    Note scdisp[8];
    Note chdbase[3];
    Note chdnotes[3];
    for (int i = 0; i < cmajor.size; i++) {
        printNote("Major Scale of ", cmajor.notes[i], " ");
        printf("(Frequency : %f - Wavelength : %f)\n", getFreqOrWave(cmajor.notes[i], STANDARD, FREQUENCY), getFreqOrWave(cmajor.notes[i], STANDARD, WAVELENGTH));
        printScale("", getScale(cmajor.notes[i], &MAJOR_SCALE, scdisp, ASCEND), "\n");
        printNote("Major Triad of ", cmajor.notes[i], "\n");
        printChord("", getChord(cmajor.notes[i], &MAJOR_TRIAD, chdbase, chdnotes), "\n\n");
    }
}
