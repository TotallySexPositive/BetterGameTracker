// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_RESULTOBJECT_BGT_TYPES_H_
#define FLATBUFFERS_GENERATED_RESULTOBJECT_BGT_TYPES_H_

#include "flatbuffers/flatbuffers.h"

namespace BGT {
namespace Types {

struct Results;
struct ResultsBuilder;

enum Result : int8_t {
  Result_WIN = 0,
  Result_LOSS = 1,
  Result_UNINITIALIZED = 2,
  Result_MIN = Result_WIN,
  Result_MAX = Result_UNINITIALIZED
};

inline const Result (&EnumValuesResult())[3] {
  static const Result values[] = {
    Result_WIN,
    Result_LOSS,
    Result_UNINITIALIZED
  };
  return values;
}

inline const char * const *EnumNamesResult() {
  static const char * const names[4] = {
    "WIN",
    "LOSS",
    "UNINITIALIZED",
    nullptr
  };
  return names;
}

inline const char *EnumNameResult(Result e) {
  if (flatbuffers::IsOutRange(e, Result_WIN, Result_UNINITIALIZED)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesResult()[index];
}

struct Results FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ResultsBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_WINS = 4,
    VT_LOSSES = 6,
    VT_MMR = 8,
    VT_PREVIOUS = 10,
    VT_MODE = 12
  };
  int16_t wins() const {
    return GetField<int16_t>(VT_WINS, 0);
  }
  int16_t losses() const {
    return GetField<int16_t>(VT_LOSSES, 0);
  }
  float mmr() const {
    return GetField<float>(VT_MMR, 0.0f);
  }
  BGT::Types::Result previous() const {
    return static_cast<BGT::Types::Result>(GetField<int8_t>(VT_PREVIOUS, 2));
  }
  const flatbuffers::String *mode() const {
    return GetPointer<const flatbuffers::String *>(VT_MODE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int16_t>(verifier, VT_WINS) &&
           VerifyField<int16_t>(verifier, VT_LOSSES) &&
           VerifyField<float>(verifier, VT_MMR) &&
           VerifyField<int8_t>(verifier, VT_PREVIOUS) &&
           VerifyOffset(verifier, VT_MODE) &&
           verifier.VerifyString(mode()) &&
           verifier.EndTable();
  }
};

struct ResultsBuilder {
  typedef Results Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_wins(int16_t wins) {
    fbb_.AddElement<int16_t>(Results::VT_WINS, wins, 0);
  }
  void add_losses(int16_t losses) {
    fbb_.AddElement<int16_t>(Results::VT_LOSSES, losses, 0);
  }
  void add_mmr(float mmr) {
    fbb_.AddElement<float>(Results::VT_MMR, mmr, 0.0f);
  }
  void add_previous(BGT::Types::Result previous) {
    fbb_.AddElement<int8_t>(Results::VT_PREVIOUS, static_cast<int8_t>(previous), 2);
  }
  void add_mode(flatbuffers::Offset<flatbuffers::String> mode) {
    fbb_.AddOffset(Results::VT_MODE, mode);
  }
  explicit ResultsBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Results> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Results>(end);
    return o;
  }
};

inline flatbuffers::Offset<Results> CreateResults(
    flatbuffers::FlatBufferBuilder &_fbb,
    int16_t wins = 0,
    int16_t losses = 0,
    float mmr = 0.0f,
    BGT::Types::Result previous = BGT::Types::Result_UNINITIALIZED,
    flatbuffers::Offset<flatbuffers::String> mode = 0) {
  ResultsBuilder builder_(_fbb);
  builder_.add_mode(mode);
  builder_.add_mmr(mmr);
  builder_.add_losses(losses);
  builder_.add_wins(wins);
  builder_.add_previous(previous);
  return builder_.Finish();
}

inline flatbuffers::Offset<Results> CreateResultsDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int16_t wins = 0,
    int16_t losses = 0,
    float mmr = 0.0f,
    BGT::Types::Result previous = BGT::Types::Result_UNINITIALIZED,
    const char *mode = nullptr) {
  auto mode__ = mode ? _fbb.CreateString(mode) : 0;
  return BGT::Types::CreateResults(
      _fbb,
      wins,
      losses,
      mmr,
      previous,
      mode__);
}

inline const BGT::Types::Results *GetResults(const void *buf) {
  return flatbuffers::GetRoot<BGT::Types::Results>(buf);
}

inline const BGT::Types::Results *GetSizePrefixedResults(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<BGT::Types::Results>(buf);
}

inline bool VerifyResultsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<BGT::Types::Results>(nullptr);
}

inline bool VerifySizePrefixedResultsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<BGT::Types::Results>(nullptr);
}

inline void FinishResultsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<BGT::Types::Results> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedResultsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<BGT::Types::Results> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Types
}  // namespace BGT

#endif  // FLATBUFFERS_GENERATED_RESULTOBJECT_BGT_TYPES_H_
