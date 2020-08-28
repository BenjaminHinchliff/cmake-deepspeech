#include <memory>
#include <iostream>
#include <filesystem>

#include "deepspeech.h"
#include "portaudio.h"

#include "model.h"
#include "deepsmartptrs.h"

namespace fs = std::filesystem;

int main() {
    PaError paErr = Pa_Initialize();
    if (paErr != paNoError) {
        std::cerr << "Portaudio initialize error: " << Pa_GetErrorText(paErr) << '\n';
        return 1;
    }
    std::cout << "Initialized portaudio" << '\n';

    std::cout << MODEL_PATH << '\n';
    ModelState *rawCtx;
    int status = DS_CreateModel(MODEL_PATH, &rawCtx);
    if (status != 0) {
        UniqueFreedPtr<char> err(DS_ErrorCodeToErrorMessage(status));
        std::cerr << "Couldn't create model: " << err.get() << '\n';
        return 1;
    }
    std::cout << "Model created!" << '\n';
    UniqueModelState ctx(rawCtx);


    paErr = Pa_Terminate();
    if (paErr != paNoError) {
        std::cerr << "Portaudio termination error: " << Pa_GetErrorText(paErr) << '\n';
        return 1;
    }
    return 0;
}
