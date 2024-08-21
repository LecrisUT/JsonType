Name:           json-type
Summary:        C++ types for JSON-like datastructure
Version:        0.0.0
Release:        %autorelease
License:        MIT
URL:            https://github.com/LecrisUT/JsonType

Source:         %{url}/archive/refs/tags/v%{version}.tar.gz

BuildRequires:  ninja-build
BuildRequires:  cmake
BuildRequires:  gcc-c++
BuildRequires:  cmake(Catch2)


%global _description %{expand:
Minimalistic project wrapping C++ container library to provide generic
datastructure compatible with JSON, YAML, TOML.

This project provides only the Json-like type structure and manipulations.
Parsing, formatting, validation, are outside the scope of this project.
}

%description %{_description}

This package contains the runctime library.

%package        devel
Summary:        %{summary}
Requires:       cmake-template%{?_isa} = %{version}-%{release}

%description    devel %{_description}

This package contains the development files.


%prep
%autosetup -n JsonType-%{version}


%build
%cmake
%cmake_build


%install
%cmake_install


%check
%ctest -L "(unit|integration)"


%files
%doc README.md
%license LICENSE
%{_libdir}/libjson_type.so.*

%files devel
%{_libdir}/libjson_type.so
%{_includedir}/json_type.h
%{_libdir}/cmake/JsonType


%changelog
%autochangelog
