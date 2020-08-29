#include <memory>
#include <iostream>
#include <filesystem>

#include "deepspeech.h"
#include "audiofile.h"

#include "model.h"
#include "deepsmartptrs.h"

int main() {
    ModelState *rawCtx;
    int status = DS_CreateModel(MODEL_PATH, &rawCtx);
    if (status != 0) {
        UniqueFreedPtr<char> err(DS_ErrorCodeToErrorMessage(status));
        std::cerr << "Couldn't create model: " << err.get() << '\n';
        return 1;
    }
    std::cout << "Model created" << '\n';
    UniqueModelState ctx(rawCtx);



    return 0;
}
