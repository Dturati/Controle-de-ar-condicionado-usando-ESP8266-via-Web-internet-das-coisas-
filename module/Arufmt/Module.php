<?php

namespace Arufmt;

use Zend\Mvc\ModuleRouteListener;
use Zend\Mvc\MvcEvent;

use Zend\Db\TableGateway\TableGateway;
use Zend\Db\ResultSet\ResultSet;

use Zend\ModuleManager\ModuleManager;

use Arufmt\Model\Grava;
use Arufmt\Model\GravaTable as ModelGravaTable;
class Module
{
    public function onBootstrap(MvcEvent $e)
    {
        $eventManager        = $e->getApplication()->getEventManager();
        $moduleRouteListener = new ModuleRouteListener();
        $moduleRouteListener->attach($eventManager);
    }

    public function getConfig()
    {
        return include __DIR__ . '/config/module.config.php';
    }

    public function getAutoloaderConfig()
    {
        return array(
            'Zend\Loader\StandardAutoloader' => array(
                'namespaces' => array(
                    __NAMESPACE__ => __DIR__ . '/src/' . __NAMESPACE__,
                ),
            ),
        );
    }

    public function getServiceConfig()
    {
        return array(
            'factories' => array(
                'GravaTableGateway' => function ($sm) {

                    $adapter = $sm->get('Zend\Db\Adapter\Adapter');

                    $resultSetPrototype = new ResultSet();
                    $resultSetPrototype->setArrayObjectPrototype(new Grava());


                    return new TableGateway('temphum', $adapter, null, $resultSetPrototype);
                },

                'ModelGravaTable' => function ($sm) {
                    // return instacia Model NegociosvendaTable
                    return new ModelGravaTable($sm->get('GravaTableGateway'));
                },
            )
        );

    }
}
