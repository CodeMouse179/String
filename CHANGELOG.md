# Changelog

## History

### 1.8.0

Release Date : 2022/11/5

Added : String::Remove(function), String::ToLower(overload function), String::ToUpper(overload function)

Changed : SYSTEM_WINDOWS = 1, SYSTEM_LINUX = 1, SYSTEM_CXX_11 = 1, SYSTEM_CXX_14 = 1, SYSTEM_CXX_17 = 1, SYSTEM_CXX_20 = 1

### 1.7.0

Release Date : 2022/11/5

Added : String::Copy(function), String::GetTypeCode(function), String::ToString(overload function)

### 1.6.0

Release Date : 2022/11/5

Added : String::Replace(function), String::ToCharArray(function), String::ToString(function)

Changed : make String::String static

### 1.5.1

Release Date : 2022/11/5

Added : StringU8(macro), StringU16(macro), StringU32(macro)

### 1.5.0

Release Date : 2022/11/1

Added : String::ConvertString(function)

### 1.4.0

Release Date : 2022/10/28

Added : String::UTF8CharCount(function)

Fixed : String::IsValidUTF8

### 1.3.4

Release Date : 2022/10/28

Fixed : #if SYSTEM_CXX_17 => #ifdef SYSTEM_CXX_17 in String::Concat, String::Format

### 1.3.3

Release Date : 2022/10/28

Fixed : SYSTEM_CXX_11, SYSTEM_CXX_14, SYSTEM_CXX_17

### 1.3.2

Release Date : 2022/10/28

Added : SYSTEM_STRING_SET_UTF8(macro)

### 1.3.1

Release Date : 2022/10/28

Added : SYSTEM_STRING_VERSION(macro)

### 1.3.0

Release Date : 2022/10/27

Added : String::Trim(overload function), String::TrimEnd(overload function), String::TrimStart(overload function)

Changed : String::Equals, make String::IsValidUTF8 to public function.

### 1.2.0

Release Date : 2022/10/27

Added : T8(macro)

### 1.1.0

Release Date : 2022/10/27

Added : String::IsValidUTF8(function)

### 1.0.1

Release Date : 2022/10/26

Added : __SYSTEM_STRING_ONLY(macro)

### 1.0.0

Release Date : 2022/10/26

First release!