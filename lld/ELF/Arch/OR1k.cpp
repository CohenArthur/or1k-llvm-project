//===- OR1k.cpp -----------------------------------------------------------===//
//
//                             The LLVM Linker
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "InputFiles.h"
#include "Target.h"
#include "llvm/BinaryFormat/ELF.h"

using namespace llvm::ELF;
using namespace lld;
using namespace lld::elf;

namespace {
class OR1k final : public TargetInfo {
public:
  OR1k(){};

  virtual RelExpr getRelExpr(RelType Type, const Symbol &S,
                             const uint8_t *Loc) const {
      error(getErrorLocation(Loc) +
            "wtf am I doing here " + toString(Type));
    return R_ABS;
  };

  virtual void relocateOne(uint8_t *Loc, RelType Type, uint64_t Val) const {
    switch (Type) {
    case R_OR1K_NONE:
      *Loc = Val;
      break;
    default:
      error(getErrorLocation(Loc) +
            "unrecognized relocation: " + toString(Type));
      // case R_OR1K_32:
      // case R_OR1K_16:
      // case R_OR1K_8:
      // case R_OR1K_LO_16_IN_INSN:
      // case R_OR1K_HI_16_IN_INSN:
      // case R_OR1K_INSN_REL_26:
      // case R_OR1K_GNU_VTENTRY:
      // case R_OR1K_GNU_VTINHERIT:
      // case R_OR1K_32_PCREL:
      // case R_OR1K_16_PCREL:
      // case R_OR1K_8_PCREL:
      // case R_OR1K_GOTPC_HI16:
      // case R_OR1K_GOTPC_LO16:
      // case R_OR1K_GOT16:
      // case R_OR1K_PLT26:
      // case R_OR1K_GOTOFF_HI16:
      // case R_OR1K_GOTOFF_LO16:
      // case R_OR1K_COPY:
      // case R_OR1K_GLOB_DAT:
      // case R_OR1K_JMP_SLOT:
      // case R_OR1K_RELATIVE:
    }
  };
};
} // namespace

TargetInfo *elf::getOR1kTargetInfo() {
  static OR1k Target;
  return &Target;
}
