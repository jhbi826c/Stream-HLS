# ###############################################################################
# streamhls-lsp-server
#
# The streamhls-lsp-server MLIR language server.
# ###############################################################################

project(streamhls-lsp-server)

add_llvm_tool(${PROJECT_NAME}
    streamhls-lsp-server.cpp
)
llvm_update_compile_flags(${PROJECT_NAME})

# Link all standard MLIR dialect and conversion libs.
get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    MLIRLspServerLib

    ${dialect_libs}
    ${conversion_libs}
)
