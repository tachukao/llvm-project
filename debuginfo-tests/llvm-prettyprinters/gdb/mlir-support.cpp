#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Identifier.h"
#include "mlir/IR/Location.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/OperationSupport.h"

mlir::MLIRContext Context;

auto Identifier = mlir::Identifier::get("foo", &Context);
mlir::OperationName OperationName("FooOp", &Context);
mlir::Value Value({reinterpret_cast<void *>(0x8),
                   mlir::Value::Kind::TrailingOpResult});

mlir::Type Type(nullptr);
mlir::Type IndexType = mlir::IndexType::get(&Context);
mlir::Type IntegerType =
    mlir::IntegerType::get(3, mlir::IntegerType::Unsigned, &Context);
mlir::Type FloatType = mlir::Float32Type::get(&Context);
mlir::Type MemRefType = mlir::MemRefType::get({4, 5}, FloatType);
mlir::Type UnrankedMemRefType = mlir::UnrankedMemRefType::get(IntegerType, 6);
mlir::Type VectorType = mlir::VectorType::get({1, 2}, FloatType);
mlir::Type TupleType =
    mlir::TupleType::get(mlir::TypeRange({IndexType, FloatType}), &Context);

auto UnknownLoc = mlir::UnknownLoc::get(&Context);
auto FileLineColLoc = mlir::FileLineColLoc::get("file", 7, 8, &Context);
auto OpaqueLoc = mlir::OpaqueLoc::get<uintptr_t>(9, &Context);
auto NameLoc = mlir::NameLoc::get(Identifier, &Context);
auto CallSiteLoc = mlir::CallSiteLoc::get(FileLineColLoc, OpaqueLoc);
auto FusedLoc = mlir::FusedLoc::get({FileLineColLoc, NameLoc}, &Context);

mlir::Attribute UnitAttr = mlir::UnitAttr::get(&Context);
mlir::Attribute FloatAttr = mlir::FloatAttr::get(FloatType, 1.0);
mlir::Attribute IntegerAttr = mlir::IntegerAttr::get(IntegerType, 10);
mlir::Attribute TypeAttr = mlir::TypeAttr::get(IndexType);
mlir::Attribute ArrayAttr = mlir::ArrayAttr::get({UnitAttr}, &Context);
mlir::Attribute StringAttr = mlir::StringAttr::get("foo", &Context);
mlir::Attribute ElementsAttr = mlir::DenseElementsAttr::get(
    VectorType.cast<mlir::ShapedType>(), llvm::ArrayRef<float>{2.0f, 3.0f});

int main() { return 0; }
