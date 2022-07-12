%define _unpackaged_files_terminate_build 1

Name: client-application
Version: 0.1.0
Release: alt1

Summary: Optical spectrometer measurement application.
License: GPLv2+
Group: Other
Url: https://github.com/august-alt/client-application

BuildRequires: cmake
BuildRequires: rpm-macros-cmake
BuildRequires: cmake-modules
BuildRequires: gcc-c++
BuildRequires: qt5-base-devel
BuildRequires: qt5-declarative-devel
BuildRequires: qt5-tools-devel
BuildRequires: qt5-base-common
BuildRequires: doxygen

BuildRequires: desktop-file-utils ImageMagick-tools

Source0: %name-%version.tar

%description
Optical spectrometer measurement application.

%prep
%setup -q

%build
%cmake
%cmake_build

%install
%cmakeinstall_std

%files
%doc README.md
%_bindir/client-application

%changelog
* Mon Jul 05 2021 Evgeny Sinelnikov <sin@altlinux.org> 0.1.0-alt1
- Initial build
