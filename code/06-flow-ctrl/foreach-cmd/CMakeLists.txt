

foreach(outerVar IN ITEMS a b c)
  unset(s)
  foreach(innerVar IN ITEMS 1 2 3 4 5 6)  
    list(APPEND s "${outerVar}${innerVar}")
    list(LENGTH s length)
    
    message("length: ${length}")
  
    if(length GREATER_EQUAL 3)
      break()
    endif()
    
    if(outerVar STREQUAL "b")
      continue()
    endif()
    message("Processing ${outerVar}-${innerVar}")
  endforeach()

  message("Accumulated list: ${s}")
endforeach()