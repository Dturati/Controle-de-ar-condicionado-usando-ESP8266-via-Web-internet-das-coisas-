<?php


namespace Arufmt;

return array(
    'router' => array(
        'routes' => array(

            'home' => array(
                'type' => 'Zend\Mvc\Router\Http\Literal',
                'options' => array(
                    'route'    => '/',
                    'defaults' => array(
                        'controller' => 'index\Controller\Index',
                        'action'     => 'index',
                    ),
                ),

            ),

            'gravar' => array(
                'type' => 'Segment',
                'options' => array(
                    'route'    => '/gravar[/:action][/:temp][/:hum]',
                    'constraints' =>[
                        'action' => '[a-zA-Z][a-zA-Z0-9_-]*',
                        'id'     => '[a-zA-Z][a-zA-Z0-9_-]*',
                    ],
                    'defaults' => array(
                        'controller' => 'index\Controller\Index',
                        'action'     => 'gravar',
                    ),
                ),
            ),

            'relatorio' => array(
                'type' => 'Segment',
                'options' => array(
                    'route'    => '/relatorio[/:action][/:temp][/:hum]',
                    'constraints' =>[
                        'action' => '[a-zA-Z][a-zA-Z0-9_-]*',
                        'id'     => '[a-zA-Z][a-zA-Z0-9_-]*',
                    ],
                    'defaults' => array(
                        'controller' => 'index\Controller\Index',
                        'action'     => 'relatorio',
                    ),
                ),
            ),

            'aumentar' => array(
                'type' => 'Segment',
                'options' => array(
                    'route'    => '/aumentar'   ,
                    'defaults' => array(
                        'controller' => 'index\Controller\Index',
                        'action'     => 'aumentar',
                    ),
                ),
            ),



            'index' => array(
                'type'    => 'Literal',
                'options' => array(
                    'route'    => '/index',
                    'defaults' => array(
                        '__NAMESPACE__' => 'index\Controller',
                        'controller'    => 'Index',
                        'action'        => 'index',
                    ),
                ),
                'may_terminate' => true,
                'child_routes' => array(
                    'default' => array(
                        'type'    => 'Segment',
                        'options' => array(
                            'route'    => '/[:controller[/:action]]',
                            'constraints' => array(
                                'controller' => '[a-zA-Z][a-zA-Z0-9_-]*',
                                'action'     => '[a-zA-Z][a-zA-Z0-9_-]*',
                            ),
                            'defaults' => array(
                            ),
                        ),
                    ),
                ),
            ),
        ),
    ),
    'service_manager' => array(
        'abstract_factories' => array(
            'Zend\Cache\Service\StorageCacheAbstractServiceFactory',
            'Zend\Log\LoggerAbstractServiceFactory',
        ),
        'factories' => array(
            'translator' => 'Zend\Mvc\Service\TranslatorServiceFactory',
        ),
    ),
    'translator' => array(
        'locale' => 'en_US',
        'translation_file_patterns' => array(
            array(
                'type'     => 'gettext',
                'base_dir' => __DIR__ . '/../language',
                'pattern'  => '%s.mo',
            ),
        ),
    ),
    'controllers' => array(
        'invokables' => array(
            'index\Controller\Index' => Controller\IndexController::class
        ),
    ),
    'view_manager' => array(
        'display_not_found_reason' => true,
        'display_exceptions'       => true,
        'doctype'                  => 'HTML5',
        'not_found_template'       => 'error/404',
        'exception_template'       => 'error/index',
        'template_map' => array(
            'layout/layout'           => __DIR__ . '/../view/layout/layout.phtml',
            'index/index/index' => __DIR__ . '/../view/index/index/index.phtml',
            'error/404'               => __DIR__ . '/../view/error/404.phtml',
            'error/index'             => __DIR__ . '/../view/error/index.phtml',
        ),
        'template_path_stack' => array(
            __DIR__ . '/../view',
        ),
        //para ajax e jason
        'strategies' => [
            'ViewJsonStrategy',
        ],
    ),
    // Placeholder for console routes
    'console' => array(
        'router' => array(
            'routes' => array(
            ),
        ),
    ),
);
