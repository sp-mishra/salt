#include <utils/Log.hpp>
#include <xxhash.hpp>

#include "./controller/MyController.hpp"
#include "./AppComponent.hpp"

#include "oatpp/network/server/Server.hpp"

using namespace salt;

void run() {

    /* Register Components in scope of run() method */
    AppComponent components;

    /* Get router component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    /* Create MyController and add all of its endpoints to router */
    auto myController = std::make_shared<MyController>();
    myController->addEndpointsToRouter(router);

    /* Get connection handler component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::server::ConnectionHandler>, connectionHandler);

    /* Get connection provider component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

    /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
    oatpp::network::server::Server server(connectionProvider, connectionHandler);

    /* Priny info about server port */
    OATPP_LOGI("MyApp", "Server running on port %s", connectionProvider->getProperty("port").getData());

    /* Run server */
    server.run();

}

int main(int argc, char **argv) {
    info("Testing Normal Log");
    info("Testing params {}", 12);
    critical("Testing params {}", 12);
    // standalone hash
    const std::array<int, 4> input {322, 2137, 42069, 65536};
    const xxh::hash_t<32> hash = xxh::xxhash<32>(input);

    oatpp::base::Environment::init();

    run();

    /* Print how much objects were created during app running, and what have left-probably leaked */
    /* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
    info("\nEnvironment:\n");
    info("objectsCount = {}",  oatpp::base::Environment::getObjectsCount());
    info("objectsCreated = {}",  oatpp::base::Environment::getObjectsCreated());

    oatpp::base::Environment::destroy();
    return 0;
}