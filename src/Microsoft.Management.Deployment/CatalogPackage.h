// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once
#include "CatalogPackage.g.h"

namespace winrt::Microsoft::Management::Deployment::implementation
{
    struct CatalogPackage : CatalogPackageT<CatalogPackage>
    {
        CatalogPackage() = default;

#if !defined(INCLUDE_ONLY_INTERFACE_METHODS)
        void Initialize(
            ::AppInstaller::Repository::Source source,
            std::shared_ptr<::AppInstaller::Repository::IPackage> package);
#endif

        hstring Id();
        hstring Name();
        winrt::Microsoft::Management::Deployment::PackageVersionInfo InstalledVersion();
        winrt::Windows::Foundation::Collections::IVectorView<winrt::Microsoft::Management::Deployment::PackageVersionId> AvailableVersions();
        winrt::Microsoft::Management::Deployment::PackageVersionInfo DefaultInstallVersion();
        winrt::Microsoft::Management::Deployment::PackageVersionInfo GetPackageVersionInfo(winrt::Microsoft::Management::Deployment::PackageVersionId const& versionKey);
        bool IsUpdateAvailable();

#if !defined(INCLUDE_ONLY_INTERFACE_METHODS)
    private:
        ::AppInstaller::Repository::Source m_source;
        std::shared_ptr<::AppInstaller::Repository::IPackage> m_package;
        Windows::Foundation::Collections::IVector<winrt::Microsoft::Management::Deployment::PackageVersionId> m_availableVersions{ winrt::single_threaded_vector<winrt::Microsoft::Management::Deployment::PackageVersionId>() };
        winrt::Microsoft::Management::Deployment::PackageVersionInfo m_installedVersion{ nullptr };
        winrt::Microsoft::Management::Deployment::PackageVersionInfo m_defaultInstallVersion{ nullptr };
        std::once_flag m_installedVersionOnceFlag;
        std::once_flag m_availableVersionsOnceFlag;
        std::once_flag m_defaultInstallVersionOnceFlag;
#endif
    };
}