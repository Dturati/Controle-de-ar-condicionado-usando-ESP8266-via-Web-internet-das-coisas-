<?php
/**
 * Zend Framework (http://framework.zend.com/)
 *
 * @link      http://github.com/zendframework/zf2 for the canonical source repository
 * @copyright Copyright (c) 2005-2015 Zend Technologies USA Inc. (http://www.zend.com)
 * @license   http://framework.zend.com/license/new-bsd New BSD License
 */

namespace Zend\Validator\File;

use Traversable;
use Zend\Stdlib\ArrayUtils;

/**
 * Validator which checks if the file already exists in the directory
 */
class IsCompressed extends MimeType
{
    /**
     * @const string Error constants
     */
    const FALSE_TYPE   = 'fileIsCompressedFalseType';
    const NOT_DETECTED = 'fileIsCompressedNotDetected';
    const NOT_READABLE = 'fileIsCompressedNotReadable';

    /**
     * @var array Error message templates
     */
    protected $messageTemplates = array(
        self::FALSE_TYPE   => "File is not compressed, '%type%' detected",
        self::NOT_DETECTED => "The mimetype could not be detected from the file",
        self::NOT_READABLE => "File is not readable or does not exist",
    );

    /**
     * Sets validator options
     *
     * @param string|array|Traversable $options
     */
    public function __construct($options = array())
    {
        // http://hul.harvard.edu/ois/systems/wax/wax-public-help/mimetypes.htm
        $default = array(
            'index/arj',
            'index/gnutar',
            'index/lha',
            'index/lzx',
            'index/vnd.ms-cab-compressed',
            'index/x-ace-compressed',
            'index/x-arc',
            'index/x-archive',
            'index/x-arj',
            'index/x-bzip',
            'index/x-bzip2',
            'index/x-cab-compressed',
            'index/x-compress',
            'index/x-compressed',
            'index/x-cpio',
            'index/x-debian-package',
            'index/x-eet',
            'index/x-gzip',
            'index/x-java-pack200',
            'index/x-lha',
            'index/x-lharc',
            'index/x-lzh',
            'index/x-lzma',
            'index/x-lzx',
            'index/x-rar',
            'index/x-sit',
            'index/x-stuffit',
            'index/x-tar',
            'index/zip',
            'index/x-zip',
            'index/zoo',
            'multipart/x-gzip',
        );

        if ($options instanceof Traversable) {
            $options = ArrayUtils::iteratorToArray($options);
        }

        if ($options === null) {
            $options = array();
        }

        parent::__construct($options);

        if (!$this->getMimeType()) {
            $this->setMimeType($default);
        }
    }
}
