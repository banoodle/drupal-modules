<?php

namespace Drupal\superstar\Plugin\Field\FieldFormatter;

use Drupal\Component\Utility\Html;
use Drupal\Core\Field\FieldItemInterface;
use Drupal\Core\Field\FieldItemListInterface;
use Drupal\Core\Field\FormatterBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Plugin implementation of the 'superstar_ratings_stars' formatter.
 *
 * @FieldFormatter(
 *   id = "superstar_ratings_stars",
 *   label = @Translation("Superstar ratings stars"),
 *   field_types = {
 *     "decimal",
 *     "list_integer"
 *   }
 * )
 */
class SuperstarFieldFormatter extends FormatterBase {

  /**
   * {@inheritdoc}
   */
  public static function defaultSettings() {
    return [
      // Implement default settings.
    ] + parent::defaultSettings();
  }

  /**
   * {@inheritdoc}
   */
  public function settingsForm(array $form, FormStateInterface $form_state) {
    return [
      // Implement settings form.
    ] + parent::settingsForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function settingsSummary() {
    $summary = [];
    // Implement settings summary.

    return $summary;
  }

  /**
   * {@inheritdoc}
   */
  public function viewElements(FieldItemListInterface $items, $langcode) {
    $elements = [];

    foreach ($items as $delta => $item) {

      // Get the value.
      $rating = $this->viewValue($item);

      // Round to nearest half.
      $rating = round($rating * 2)/2;

      // Make sure that the value is in 0 - 5 range, multiply to get width.
      $size = max(0, (min(5, $rating))) * 16;

      $elements[$delta] = [
        '#type' => 'inline_template',
        '#template' => '<div class="stars-wrapper"><span class="stars"><span style="width:{{ size }}px;"></span></span></div>',
        '#context' => [
          'size' => $size
        ]
      ];
    }

    return $elements;
  }

  /**
   * Generate the output appropriate for one field item.
   *
   * @param \Drupal\Core\Field\FieldItemInterface $item
   *   One field item.
   *
   * @return string
   *   The textual output generated.
   */
  protected function viewValue(FieldItemInterface $item) {
    // The text value has no text format assigned to it, so the user input
    // should equal the output, including newlines.
    return nl2br(Html::escape($item->value));
  }

}
