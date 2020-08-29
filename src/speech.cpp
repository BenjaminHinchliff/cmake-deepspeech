#include <memory>
#include <iostream>
#include <limits>

#include "deepspeech.h"
#include "audiofile.h"

#include "model.config.h"
#include "audio.config.h"
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

    int targetRate = DS_GetModelSampleRate(ctx.get());
    int targetBitDepth = 16;

    AudioFile<double> speech;
    speech.load(AUDIO_PATH);
    if (speech.getSampleRate() != targetRate) {
        std::cerr << "Input file must have a sample rate of " << targetRate << '\n';
        return 1;
    }
    if (speech.getBitDepth() != targetBitDepth) {
        std::cerr << "Input file bit depthh must be " << targetBitDepth << '\n';
        return 1;
    }
    if (!speech.isMono()) {
        std::cerr << "Input file must be mono" << '\n';
        return 1;
    }

    std::vector<int16_t> buffer;
    buffer.reserve(speech.samples[0].size());
    std::transform(
        speech.samples[0].cbegin(),
        speech.samples[0].cend(),
        std::back_inserter(buffer),
        [](const double &sample) {
            return static_cast<int16_t>(
                sample * std::numeric_limits<int16_t>::max()
            );
        }
    );
    std::cout << "file loaded" << '\n';
    
    std::cout << DS_SpeechToText(
        ctx.get(),
        reinterpret_cast<const int16_t *>(buffer.data()),
        static_cast<uint32_t>(buffer.size())
    ) << '\n';

    return 0;
}
