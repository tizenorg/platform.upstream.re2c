Name:           re2c
Version:        0.13.5
Release:        37
License:        SUSE-Public-Domain
Summary:        Tool for generating C-based recognizers from regular expressions
Url:            http://re2c.org/
Group:          Development/Libraries/C and C++
Source:         %{name}-%{version}.tar.bz2
BuildRequires:  gcc-c++

%description
re2c is a tool for writing fast and flexible lexers. Unlike other such
tools, it concentrates solely on generating efficient code for matching
regular expressions. This makes it suitable for a wide variety of
applications. The generated scanners approach hand-crafted ones in
terms of size and speed.

%prep
%setup -q
find -type d -name .svn -print0 | xargs -r0 rm -rf
find CHANGELOG lessons examples -type f -print0 \
    | xargs -r0 chmod -v a-x

%build
%configure
make %{?_smp_mflags} re2c
#regenerate file scanner.cc
rm -f scanner.cc
./re2c -g scanner.re > scanner.cc
rm -f re2c scanner.o
make %{?_smp_mflags}

%check
make test

%install
%make_install

%files
%defattr(-,root,root,-)
%{_bindir}/re2c
%{_mandir}/man1/re2c.1*

%changelog
