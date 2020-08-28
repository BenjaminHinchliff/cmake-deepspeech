struct ModelDeleter {
    void operator()(ModelState *model) {
        DS_FreeModel(model);
    }
};

struct MallocDeleter {
    void operator()(void *p) {
        free(p);
    }
};

using UniqueModelState = std::unique_ptr<ModelState, ModelDeleter>;
template<typename T>
using UniqueFreedPtr = std::unique_ptr<T, MallocDeleter>;
