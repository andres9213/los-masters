<?php
/**
 * @file
 * Form for estimator
 */

/**
 * Image and link form().
 */
function im_site_config_estimator_form($form, &$form_state){
	$form['image'] = array(
		'#title' => t('Images:'),
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
		);
  $form['image']['im_estimator_image'] = array(
    '#title' => t('Image:'),
    '#type' => 'managed_file',
    '#description' => t('Upload the image for the estimator'),
    '#default_value' => variable_get('im_estimator_image', ''),
    '#upload_location' => 'public://',
    );
  $form['image']['im_estimator_style'] = array(
    '#title' => t('Image Style'),
    '#type' => 'select',
    '#options' => im_get_image_styles(),
    '#default_value' => variable_get('im_estimator_style', 2),
    '#access' => user_access('administer site configuration'),
    '#description' => t('Select the image style for the prices.'),
    );
  $form['image']['im_estimator_link'] = array(
    '#title' => t('Link:'),
    '#type' => 'textfield',
    '#format' => 'full_html',
    '#description' => t('Here, you can write the link for the image'),
    '#default_value' => variable_get('im_estimator_link'),
    );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('submit'),
    );
  return $form;
}

/*
 * Submits the form.
 */

function im_site_config_estimator_form_submit($form, &$form_state){
  $banner_image = variable_get('im_estimator_image', '');
  // Image processing for the main image.
  if($form_state['values']['im_estimator_image'] == 0){
    if($banner_image != 0){
      $file = file_load($banner_image);
      file_delete($file, TRUE);
    }
  }
  else{
    $file = file_load($form_state['values']['im_estimator_image']);
    $file->status = FILE_STATUS_PERMANENT;
    $file_save($file);
    file_usage_add($file, 'im_site_config', 'module', $file->fid);
  }
  variable_set('im_estimator_image', $form_state['values']['im_estimator_image']);
  variable_set('im_estimator_style', $form_state['values']['im_estimator_style']);
  variable_set('im_estimator_link', $form_state['values']['im_estimator_link']);
  drupal_set_message(t('Changes saved'));
}