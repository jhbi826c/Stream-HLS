/// Main entry point for the streamhls-mlir MLIR language server.

#include "streamhls/InitAllDialects.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/InitAllDialects.h"
#include "mlir/Tools/mlir-lsp-server/MlirLspServerMain.h"

using namespace mlir;

static int asMainReturnCode(LogicalResult r)
{
    return r.succeeded() ? EXIT_SUCCESS : EXIT_FAILURE;
}

int main(int argc, char* argv[])
{
    DialectRegistry registry;
    registerAllDialects(registry);
  mlir::streamhls::registerAllDialects(registry);

    return asMainReturnCode(MlirLspServerMain(argc, argv, registry));
}
