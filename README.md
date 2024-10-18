# TestApp

This is a new default template MFC app and a new WAP project to reproduce the issue. In the toolbar of the app I have added a Test menu that has a GetData menu item in it. When that is clicked, .NET code from the C++/CLI project is ran, which will crash the app if the .NET 8.0 runtime is not installed, but will display a popup of the SQL sort order if the .NET 8.0 runtime is installed.

TestApp.Package is the Windows App Packaging Project. TestApp.Mfc is the MFC app project. TestApp.MfcExt is the MFC extension dll project that uses C++/CLI (CLR).

The signing cert was created with visual studio under my user name with no password and is included under the TestApp.Package. The cert is located at “\TestApp.Package\TestApp.Package_TemporaryKey.pfx”.
