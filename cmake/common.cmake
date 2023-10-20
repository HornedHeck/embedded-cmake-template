function(target_enable_lint TARGET)
  set_target_properties(${TARGET} PROPERTIES C_CLANG_TIDY "clang-tidy")
endfunction(target_enable_lint TARGET)
