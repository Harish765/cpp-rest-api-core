from conans import ConanFile, CMake


class RESTAPICoreTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake_find_package"
    options = {"gtest": ["1.7.0", "1.8.1"], "OpenSSL": ["1.0.2n"]}
    default_options = {"gtest":"1.8.1", "OpenSSL":"1.0.2n"}

    def configure(self):
        self.options["RESTAPICore"].gtest = self.options.gtest
        self.options["RESTAPICore"].OpenSSL = self.options.OpenSSL

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst=("bin/%s" % self.settings.build_type), src="bin")
        self.copy("*.dylib*", dst=("bin/%s" % self.settings.build_type), src="lib")
        self.copy('*.so*', dst=("bin/%s" % self.settings.build_type), src='lib')

    def test(self):
        cmake = CMake(self)
        cmake.test()
