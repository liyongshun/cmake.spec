cmake_host_system_information(RESULT _host_name QUERY HOSTNAME)
cmake_host_system_information(RESULT processor_desc QUERY PROCESSOR_DESCRIPTION)
cmake_host_system_information(RESULT processor_name QUERY PROCESSOR_NAME)

message(${_host_name})
message(${processor_desc})
message(${processor_name})
